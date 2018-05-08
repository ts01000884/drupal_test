<!--<pre>-->
<!--    --><?php //dpm($event_node); ?>
<!---->
<!--</pre>-->


<div id="lastest_event_container" class="lastest_event_container">
    <?php print render($title); ?>
    <?php foreach ($event_node as $k => $node) { ?>

        <div class="lastest_event_item">

            <?php print render($node['title_date']); ?>
<!--            -->
            <?php print render($node['node_context']); ?>

        </div>
    <?php } ?>
</div>






<?php print render($title); ?>
<div id="lastest_event_container" class="lastest_event_container">
    <div class="lastest_event_head">
        <div class="fl cell"><img src="<?php echo path_to_theme() . '/img/red.gif'; ?>" height="40"></div>
        <div class="fl cell"><span class="text white20">最新活動 | LASTEST EVENTS</span></div>
    </div>
    <?php foreach ($event_node_list as $k => $node) { ?>

        <div class="lastest_event_item">
            <div class="fl event_date">
                <div class="activity-date">
                    <span class="month"><?php echo date('F', $node->field_event_start_time[LANGUAGE_NONE][0]['value']); ?></span><span
                            class="day"><?php echo date('d', $node->field_event_start_time[LANGUAGE_NONE][0]['value']); ?></span><span
                            class="year"><?php echo date('Y', $node->field_event_start_time[LANGUAGE_NONE][0]['value']); ?>
                </span>
                </div>
            </div>
            <div class="event_content">
                <div class="event_content_wrap"><a title="<?php echo $node->title; ?>" href="node/<?php echo $node->nid ;?>"
                                                   class="activity_title" target="_self"><?php echo $node->title; ?></a><br><span
                            class="titleblue">活動日期：<?php echo date('Y-m-d ', $node->field_event_start_time[LANGUAGE_NONE][0]['value']);echo get_chinese_weekday(date('w', $node->field_event_start_time[LANGUAGE_NONE][0]['value'])); ?></span><br><span
                            class="titleblue">報名時間：<?php echo date('Y-m-d H:i', $node->field_event_start_signin_time[LANGUAGE_NONE][0]['value']); ?> ～ <?php echo date('Y-m-d H:i', $node->field_event_end_signin_time[LANGUAGE_NONE][0]['value']); ?></span><br><br>
                    <div class="activity_content_wrap">
                        <div class="titleblack">
                            <table border="0" cellpadding="0" cellspacing="0" width="70%">
                                <tbody>
                                <tr>
                                    <!--                                    <td valign="top" width="8%"><strong>主辦單位：</strong></td>-->
                                    <td align="left" valign="top"><?php echo $node->field_event_subject[LANGUAGE_NONE][0]['value']?></td>
                                </tr>
                                </tbody>
                            </table>
                        </div>
                    </div>
                    <div style="clear:right; display: inline-block;"></div>
                    <div class="fr"><a title="node" href="node/<?php echo $node->nid ;?>"><i
                                    class="fa fa-info-circle fa-lg"></i> 詳細資訊</a></div>
                </div>
                <img src="images/line1.jpg" width="100%" height="10"></div>
        </div>
    <?php } ?>
</div>