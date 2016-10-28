# mqtt

The MQTT module for Drupal 7.

## Configuration

Go to `admin/config/services/mqtt/settings` and specify your mosquitto's configuration:

- Host
- Port
- Client name
- User name
- User password

> Starting the broker

```
sudo mosquitto -c /etc/mosquitto/mosquitto.conf
```

> Subscribe

```
drush mqtt-subscribe
```

Or use `drush mqtt-s` as a shortcut.
