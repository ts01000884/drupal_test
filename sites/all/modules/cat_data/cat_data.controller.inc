<?php


class Cat_dataController extends DrupalDefaultEntityController
{
    function cat_data_load($aid = NULL, $vid = NULL, $reset = FALSE)
    {
        $aids = (isset($aid) ? array($aid) : array());
        $conditions = (isset($vid) ? array('vid' => $vid) : array());
        $cat_data = cat_data_load_multiple($aids, $conditions, $reset);
        return $cat_data ? reset($cat_data) : FALSE;
    }

    function cat_data_load_multiple($aids = array(), $conditions = array(),
                                    $reset = FALSE)
    {
        return entity_load('cat_data', $aids, $conditions, $reset);
    }


    public function create($type = '')
    {
        return (object)array(
            'aid' => '',
            'type' => $type,
            'title' => '',
        );
    }

    public function save($cat_data)
    {
        $transaction = db_transaction();
        try {
            global $user;
            // Determine if we will be inserting a new cat_data.
            $cat_data->is_new = empty($cat_data->aid);
            // Set the timestamp fields.
            if (empty($cat_data->created)) {
                $cat_data->created = REQUEST_TIME;
            }
            $cat_data->changed = REQUEST_TIME;
            $cat_data->revision_timestamp = REQUEST_TIME;
            $update_cat_data = TRUE;
            // Give modules the opportunity to prepare field data for
            // saving.
            field_attach_presave('cat_data', $cat_data);
            if (!$cat_data->is_new && !empty($cat_data->revision) &&
                $cat_data->vid) {
                $cat_data->old_vid = $cat_data->vid;
                unset($cat_data->vid);
            }
            // If this is a new cat_data...
            if ($cat_data->is_new) {
                // Save the new cat_data.
                drupal_write_record('cat_data', $cat_data);
// Save the initial revision.
                $this->saveRevision($cat_data, $user->uid);
                $op = 'insert';
            } else {
                // Save the updated cat_data.
                drupal_write_record('cat_data', $cat_data, 'aid');
                if (!empty($cat_data->revision)) {
                    $this->saveRevision($cat_data, $user->uid);
                } else {
                    $this->saveRevision($cat_data, $user->uid, TRUE);
                    $update_cat_data = FALSE;
                }
                $op = 'update';
            }
// If the revision ID is new or updated, save it to the cat_data.
            if ($update_cat_data) {
                db_update('cat_data')
                    ->fields(array('vid' => $cat_data->vid))
                    ->condition('aid', $cat_data->aid)
                    ->execute();
            }
// Save fields.
            $function = 'field_attach_' . $op;
            $function('cat_data', $cat_data);
            module_invoke_all('entity_' . $op, $cat_data, 'cat_data');
// Clear internal properties.
            unset($cat_data->is_new);
// Ignore slave server temporarily to give time for the saved
// order to be propagated to the slave.
            db_ignore_slave();
            return $cat_data;
        } catch (Exception $e) {
            $transaction->rollback();
            watchdog_exception('cat_data', $e, NULL, WATCHDOG_ERROR);
            return FALSE;
        }
    }

}

?>