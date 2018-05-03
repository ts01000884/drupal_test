<?php

/**
 * Add body classes if certain regions have content.
 */
function event_list_preprocess(&$variables,&$hook) {
dpm($hook);

  // Add conditional stylesheets for IE
 // drupal_add_css(path_to_theme() . '/css/ie.css', array('group' => CSS_THEME, 'browsers' => array('IE' => 'lte IE 7', '!IE' => FALSE), 'preprocess' => FALSE));
 // drupal_add_css(path_to_theme() . '/css/ie6.css', array('group' => CSS_THEME, 'browsers' => array('IE' => 'IE 6', '!IE' => FALSE), 'preprocess' => FALSE));
}

