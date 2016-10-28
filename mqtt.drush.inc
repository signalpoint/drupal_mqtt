<?php
/**
 * Implements hook_drush_command().
 */
function mqtt_drush_command() {

  $items['mqtt-listen'] = array(
    'description' => 'Start the MQTT processor.',
    'aliases' => array('mqtt-l'),
  );

  $items['mqtt-subscribe'] = array(
    'description' => 'Subscribe to an MQTT broker/topic.',
    'aliases' => array('mqtt-s'),
  );

  $items['mqtt-publish'] = array(
    'description' => 'Publish an MQTT event.',
    'aliases' => array('mqtt-p'),
  );

  return $items;
}

/**
 * Callback for the drush-demo-command command.
 */
function drush_mqtt_subscribe() {

  $mqtt = mqtt_instantiate();
  $name = mqtt_user_name();
  $pass = mqtt_password();

  //watchdog('mqtt', '<pre>' . print_r($mqtt, TRUE) . '</pre>');
  if (!$mqtt->connect(TRUE, NULL, $name, $pass)) {
    exit;
  }
  $mqtt->close();
}

/**
 * Fire a test event.
 */
function drush_mqtt_publish() {
  $mqtt = mqtt_instantiate();

  if(!$mqtt->connect()){
    watchdog('MQTT', 'Failed to create MQTT connection');
    exit;
  }

  // Hardcode the test message.
  $mqtt->publish('/yourtopic/xxx', 'Testing message', 0);
  $mqtt->close();
}


/**
 * Callback for the drush-demo-command command.
 */
function drush_mqtt_listen() {
  $mqtt = mqtt_instantiate();

  if (!$mqtt->connect(TRUE, NULL, NULL, mqtt_password())) {
    watchdog('MQTT', 'Failed to create MQTT connection');
    exit;
  }

//  if (count($topics)) {
//    $mqtt->subscribe($topics,0);
//    while($mqtt->proc()) { }
//    $mqtt->close();
//  }
//  else {
//    print 'No topics to subscribe to';
//    exit;
//  }

}
