## Swift SF Office Sensors

Setup for Swift Navigation SF office environmental sensors.

See the
[dashboard](https://app.datadoghq.com/dash/266669/photon-temperature-dashboard?live=true).

## Usage

To setup your environment, run `make setup`. This probably requires that you
have the Particle CLI installed and the right credentials.

To build an image and perform an OTA update for the available devices, run `make
temperature`.

## Webhooks

For internal dashboarding, a Photon webhook posts to DataDog using JSON Mustache
templates (ugh) . This was setup manually through the Photon webhooks
[UI](https://console.particle.io/integrations/webhooks/58d879a16e9661161490edfd),
but you can find the template in the webhooks directory.
