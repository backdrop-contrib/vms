<?php
/**
 * @file
 * Contains the php code argument default plugin.
 */

/**
 * Default argument plugin to provide current mlid item.
 */
class vms_plugin_argument_default_mlid extends views_plugin_argument_default {
  function option_definition() {
    $options = parent::option_definition();
    $options['trail'] = array('default' => 'current');

    return $options;
  }

  function options_form(&$form, &$form_state) {
    $form['trail'] = array(
      '#type' => 'select',
      '#title' => t('Menu item(s) to return'),
      '#default_value' => $this->options['trail'],
      '#options' => array(
        'current_only' => t('Currently active mlid'),
        'trail' => t('Currently active mlid plus trail to top'),
        'exclude_current' => t('Trail to top menu link item, excluding the current mlid'),
      ),
      '#description' => t('Select which mlid should be fetched. Note that if a
        trail is included, the mlids will be built on the form 1+2+3. Make sure
        to enable the option for handling multiple values in this argument
        accordingly.'),
    );

  }

  function get_argument() {
    return vms_get_current_mlid($this->options['trail']);
  }
}
