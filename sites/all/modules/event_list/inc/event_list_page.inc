<?php


function event_list(){
    $path = drupal_get_path('module', 'event_list');
    drupal_add_css($path . '/css/style.css');

    $node_type = 'event';

    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node');
    $query->entityCondition('bundle', 'event','=');
    $query->propertyCondition('type', $node_type);
    $query->propertyCondition('status', 1);
    $query->propertyOrderBy('created', 'DESC');
    $query_result = $query->execute();


    if (isset($query_result['node'])) {

        // EFQ query results are keyed by entity ID
        $node_ids = array_keys($query_result['node']);

        $nodes = node_load_multiple($node_ids);
//        dpm($nodes);
    }
//
//    foreach($nodes as $nid){
//        $output1[]=node_load($nid->nid);
//
////        dpm($nid->nid);
////        $output1[] =node_page_view(node_load($nid->nid));
////        $output[] =node_page_view(node_load($nid));
//
//    }
//    dpm($output1);


//    $output = theme('event_list',array('event_node_list'=> $nodes));//定义模板waterfall_content


    $element = event_list_head_object();




//    $output = theme('hello',array());
    $event_node=array();
    event_list_event_date_object($nodes,$event_node);

    event_list_event_node_object($nodes,$event_node);

    $output =theme('event_list',array('event_node_list'=> $nodes,'title' => $element,'event_node'=>$event_node));//定义模板waterfall_content

    return $output;
}


function event_list_page_alter(&$page) {
    //把搜索栏移到底部.

//    dpm($page);

//    $page['footer']['search_form'] = $page['sidebar_first']['search_form'];
//    unset($page['sidebar_first']['search_form']);
//    // 去掉"powered by Drupal"区域显示
//    unset($page['footer']['system_powered-by']);
}


function get_chinese_weekday($weekday)
{
//    $weekday  = date('w', strtotime($datetime));
    $weeklist = array('日', '一', '二', '三', '四', '五', '六');
    return '星期' . $weeklist[$weekday];
}




//製作列表標題的陣列
function event_list_head_object(){

    $element = array(
        '#prefix' => '<div class="lastest_event_head">',
        '#suffix' => '</div>',
    );
    $A='<div class="fl cell"><img src="';
    $B='" height="40"></div>    <div class="fl cell"><span class="text white20">';
    $title_of_list='最新活動 | LASTEST EVENTS';
    $C='</span></div>';
    $element['#markup']=$A.drupal_get_path('module', 'event_list').'/img/red.gif'.$B.$title_of_list.$C;
    return $element;
}


//NODE標題時間
function event_list_event_date_object($nodes,&$event_node)
{

    foreach ($nodes as $k => $node) {
        $element=NULL;
        $element = array(
            '#prefix' => '<div class="fl event_date"><div class="activity-date">',
            '#suffix' => '</div></div>',
        );

        $A='<span class="month">';
        $B='</span><span class="day">';
        $C='</span><span class="year">';
        $D='</span>';


        $element['#markup'] = $A.date('F', $node->field_event_start_time[LANGUAGE_NONE][0]['value']).$B.
            date('d', $node->field_event_start_time[LANGUAGE_NONE][0]['value']).$C.
            date('Y', $node->field_event_start_time[LANGUAGE_NONE][0]['value']).$D;
        $event_node[$node->nid]['title_date']=$element;
    }



}


//建立NODE的內容
function event_list_event_node_object($nodes,&$event_node)
{
    foreach ($nodes as $k => $node) {
        $element=NULL;
        $element = array(
            '#prefix' => '<div class="event_content"><div class="event_content_wrap">',
            '#suffix' => '</div><img src="images/line1.jpg" width="100%" height="10"></div>',
        );

        $A='<a title="';

        $B='" href="node/';

        $C='"class="activity_title" target="_self">';

        $D='</a><br><span class="titleblue">活動日期：';

        $E='</span><br><span class="titleblue">報名時間：';

        $F='</span><br><br><div class="activity_content_wrap"><div class="titleblack"><table border="0" cellpadding="0" cellspacing="0" width="70%">
            <tbody><tr><td align="left" valign="top">';

        $G='</td>
                    </tr>
                    </tbody>
                </table>
            </div>
        </div>
        <div style="clear:right; display: inline-block;"></div>
        <div class="fr"><a title="node" href="node/';

        $H='"><i class="fa fa-info-circle fa-lg"></i> 詳細資訊</a></div>';

        $element['#markup'] =$A.$node->title.$B.$node->nid.$C.$node->title.$D.
            date('Y-m-d ', $node->field_event_start_time[LANGUAGE_NONE][0]['value']).
            get_chinese_weekday(date('w', $node->field_event_start_time[LANGUAGE_NONE][0]['value'])).
            $E.date('Y-m-d H:i', $node->field_event_start_signin_time[LANGUAGE_NONE][0]['value']).'～'.
            date('Y-m-d H:i', $node->field_event_end_signin_time[LANGUAGE_NONE][0]['value']).$F.
            $node->field_event_subject[LANGUAGE_NONE][0]['value'].$G.
            $node->nid.$H;

        $event_node[$node->nid]['node_context']=$element;
    }

}


?>

