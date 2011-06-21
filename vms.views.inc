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
