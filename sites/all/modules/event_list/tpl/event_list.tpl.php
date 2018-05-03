<!--<pre>-->
<!--    --><?php //dpm($event_node_list); ?>
<!---->
<!--</pre>-->
<div id="lastest_event_container" class="lastest_event_container">
    <div class="lastest_event_head">
        <div class="fl cell"><img src="img/red.gif" height="40"></div>
        <div class="fl cell"><span class="text white20">最新活動 | LASTEST EVENTS</span></div>
    </div>
<?php foreach($event_node_list as $k=>$node){ ?>

    <div class="lastest_event_item">
        <div class="fl event_date">
            <div class="activity-date">
                <span class="month">Oct</span><span class="day">21</span><span
                        class="year">2018
                </span>
            </div>
        </div>
        <div class="event_content">
            <div class="event_content_wrap"><a title="2018桃園茶馬古道全國馬拉松" href="activity_content.php?activitysn=2959"
                                               class="activity_title" target="_self"><?php echo $node->title;?></a><br><span
                        class="titleblue">活動日期：<?php echo date('Y-m-d H:i:s',$node->field_event_start_time[LANGUAGE_NONE][0]['value']);?></span><br><span class="titleblue">報名時間：2018-03-21 12:00 ～ 2018-08-31 23:59</span><br><br>
                <div class="activity_content_wrap">
                    <div class="titleblack">
                        <table border="0" cellpadding="0" cellspacing="0" width="100%">
                            <tbody>
                            <tr>
                                <td valign="top" width="8%"><strong>主辦單位：</strong></td>
                                <td align="left" valign="top">桃園市三項運動推廣協會</td>
                            </tr>
                            </tbody>
                        </table>
                    </div>
                </div>
                <div style="clear:right; display: inline-block;"></div>
                <div class="fr"><a title="2018桃園茶馬古道全國馬拉松" href="activity_content.php?activitysn=2959"><i
                                class="fa fa-info-circle fa-lg"></i> 詳細資訊</a></div>
            </div>
            <img src="images/line1.jpg" width="100%" height="10"></div>
    </div>
<?php }?>
</div>