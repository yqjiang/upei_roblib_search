<?php

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

function roblib_search_cufts_preprocess_roblib_search_cufts(&$variables) {
  global $base_url;
   if (!isset($query)) {
    if (isset($_GET['roblib_query'])) {
      $query = $_GET['roblib_query'];
    }
    else {
      return '';
    }
  }
  $spinner_path = $base_url . '/' . drupal_get_path('module', 'roblib_search') . '/img/'.'spinner.gif';
  $variables['spinner_path'] = $spinner_path;
  $search_url = $base_url .'/roblib_search/cufts/ajax/'.urlencode($query);
  drupal_add_js(drupal_get_path('module', 'roblib_search_cufts') . '/js/cufts_results.js');
  drupal_add_js(array('roblib_search_cufts' => array('search_url' => $search_url)), array('type' => 'setting'));
  
}
?>
