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

function vms_views_data_alter(&$data) {
  $data['field_data_field_test_mlid']['vms_test'] = array(
    'group' => t('VMS'),
    'title' => t('Experimental argument'),
    'field' => 'field_test_mlid_value',
    'filter' => array(
      'field' => 'field_test_mlid_value',
      'table' => 'field_data_field_test_mlid',
      'help' => t('This is an experiment.'),
      'handler'  => 'vms_handler_filter_mlid',
    ),
  );
}

/**
 * Implements hook_views_query_alter().
 *
 * This function is used instead of hook_views_query_substitutions, since it
 * has to change not only filter values, but also operators.
 */
function vms_views_query_alter($view, $query) {
  // Get the patterns we want to replace.
  $replacements = array_keys(vms_mlid_query_types());

  foreach ($query->where as &$condition_group) {
    foreach ($condition_group['conditions'] as &$condition) {
      if (in_array($condition['value'], $replacements)) {
        $condition['operator'] = ($condition['operator'] == '=') ? 'IN' : 'NOT IN';
        $condition['value'] = vms_get_current_mlid($condition['value']);
      }
    }
  }
}
