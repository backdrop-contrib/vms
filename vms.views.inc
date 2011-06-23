<?php
/**
 * @file
 * Declares the Views plugin for inheriting argument value.
 */

/**
 * Implements hook_views_plugins().
 */
function vms_views_plugins() {
  return array(
    'argument default' => array(
      'vms_current_mlid' => array(
        'title' => t('Currently active menu item link ID'),
        'handler' => 'vms_plugin_argument_default_mlid',
      ),
    ),
  );
}

/**
 * Implementation of hook_views_handlers().
 */
function vms_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'vms'),
    ),
    'handlers' => array(
      'vms_handler_filter_mlid' => array(
        'parent' => 'views_handler_filter_numeric',
        'file' => 'vms_handler_filter_mlid.inc',
      ),
    )
  );
}

/**
 * Implements hook_views_query_substitutions().
 */
function vms_views_query_substitutions() {
  return array(
    '***VMS_CURRENT***' => vms_get_current_mlid('current'),
    '***VMS_TRAIL***' => vms_get_current_mlid('trail'),
    '***VMS_EXCLUDE_CURRENT***' => vms_get_current_mlid('exclude_current'),
  );
}

// TODO: WRITE A VIEWS FILTER HANDLER THAT ALLOWS FILTER INTEGERS ON MLIDS.

/**
 * Implements hook_views_data_alter().
 */
//function viewssub_views_data_alter(&$data) {
//  $data['node']['vms_mlid_filtering'] = array(
//    'title' => t('Active menu link item'),
//    'help' => t('This sets the filter value based on the currently active
//      menu link'),
//    'real field' => 'field',
//    'filter' => array(
//      'handler' => 'viewssub_handler_filter_in_operator',
//    ),
//  );
//}
