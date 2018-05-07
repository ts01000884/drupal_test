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