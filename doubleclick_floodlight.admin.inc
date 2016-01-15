<?php

/**
 * @file
 * Admin forms and functinality for floodlight tags.
 */

/**
 * Form builder for the global floodlight settings form.
 */
function doubleclick_floodlight_admin_settings($form) {
  // Required settings.
  $form['main_tag_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Main Tag Settings'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#group' => 'settings',
  );

  $form['main_tag_settings']['doubleclick_floodlight_enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable / Disable'),
    '#default_value' => variable_get('doubleclick_floodlight_enabled', 1),
    '#description' => t('Sets if the tag will be showing or will be hidden.'),
  );

  $form['main_tag_settings']['doubleclick_floodlight_account_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Account ID'),
    '#default_value' => variable_get('doubleclick_floodlight_account_id', ''),
    '#required' => TRUE,
    '#description' => t('Floodlight account id.'),
  );

  $form['main_tag_settings']['doubleclick_floodlight_show_standard'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show Standard Tracking pixel'),
    '#default_value' => variable_get('doubleclick_floodlight_show_standard', 0),
    '#description' => t('Standard tracking pixel will be displayed if enabled.'),
  );

  $form['main_tag_settings']['doubleclick_floodlight_show_unique'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show Unique Tracking pixel'),
    '#default_value' => variable_get('doubleclick_floodlight_show_unique', 0),
    '#description' => t('Unique tracking pixel will be displayed if enabled.'),
  );

  // Optional parameters.
  $form['optional_tag_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Optional Tag Parameters'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#group' => 'settings',
  );

  $form['optional_tag_settings']['doubleclick_floodlight_type'] = array(
    '#type' => 'textfield',
    '#title' => t('Type - Group Tag String'),
    '#required' => FALSE,
    '#maxlength' => 255,
    '#default_value' => variable_get('doubleclick_floodlight_type', ''),
    '#description' => t('Group Tag String'),
  );

  $form['optional_tag_settings']['doubleclick_floodlight_cat'] = array(
    '#type' => 'textfield',
    '#title' => t('Cat - Activity Tag String'),
    '#default_value' => variable_get('doubleclick_floodlight_cat', ''),
    '#description' => t('Activity Tag String'),
  );

  $theme_default = variable_get('theme_default', 'bartik');
  $regions = system_region_list($theme_default);
  $form['optional_tag_settings']['doubleclick_floodlight_region'] = array(
    '#type' => 'select',
    '#options' => $regions,
    '#title' => t('Region where pixels will be added.'),
    '#default_value' => variable_get('doubleclick_floodlight_region', 'page_top'),
    '#description' => t('Select region which is first after the opening <body> tag.'),
  );
  return system_settings_form($form);
}

/**
 * Validate handler for the global settings form.
 */
function doubleclick_floodlight_admin_settings_validate($form, &$form_state) {
  $settings = $form_state['values'];
  // Account id is required.
  if (empty($settings['doubleclick_floodlight_account_id']) || !is_numeric($settings['doubleclick_floodlight_account_id'])) {
    form_set_error('doubleclick_floodlight_account_id', t('You need to enter a valid account id.'));
  }
}
