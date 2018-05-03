<?php


function event_list(){
    $path = drupal_get_path('module', 'event_list');



    drupal_add_css($path . '/css/style.css');
//
//    $output = '';
//
//    $query = db_select('node','n')->extend('PagerDefault');
//
//    $query->fields('n')->limit(10);
//
//    $objects = $query->execute()->fetchAll();
//
//    $rows = array();
//
//    foreach ($objects as $key=>$object) {
//
//        $row = array();
//
//        $row['nid'] = $object -> nid;
//
//        $row['title'] = $object -> title;
//
//        $rows[] = $row;
//
//    }



    $node_type = 'event';

    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node');
    $query->entityCondition('bundle', 'event','=');
    $query->propertyCondition('type', $node_type);
    $query->propertyCondition('status', 1);
    $query->propertyOrderBy('created', 'DESC');
    $query_result = $query->execute();

    $rows = array();

    if (isset($query_result['node'])) {
        // EFQ query results are keyed by entity ID
        $node_ids = array_keys($query_result['node']);
        $nodes = node_load_multiple($node_ids);
    }

    foreach($nodes as $nid){
        $output1[]=node_load($nid->nid);

//        dpm($nid->nid);
//        $output1[] =node_page_view(node_load($nid->nid));
//        $output[] =node_page_view(node_load($nid));

    }
//
    $output =array();
//    dpm($output1);
//    Drupal.settings.basePath+'sites/all/modules/event_list/img/red.gif'.

    $output = theme('event_list',array('event_node_list'=> $output1));//定义模板waterfall_content



    return $output;
}


function get_chinese_weekday($weekday)
{
//    $weekday  = date('w', strtotime($datetime));
    $weeklist = array('日', '一', '二', '三', '四', '五', '六');
    return '星期' . $weeklist[$weekday];
}



?>