# Dept GDPR cookie (Drupal 7)
Provides frontend shelf [cookiebar component](https://bitbucket.org/tamtam-nl/tamtam-frontend-shelf/src/e580d3cd0588402061388d6aaa96e74526a0cecf/components/cookiebar/simple/?at=develop) 1.0.0 implementation for Drupal 7

* Simple cookiebar that closes when close is pressed.
* Automatically assumes users consent when being closed.

## Requirements
* [Frontend shelf cookiebar](https://bitbucket.org/tamtam-nl/tamtam-frontend-shelf/src/e580d3cd0588402061388d6aaa96e74526a0cecf/components/cookiebar/simple/?at=develop)

## Installation

### Drupal
1. If you have satis.tamtam.nl already available in your composer.json file go to step 2. Otherwise add [satis](https://satis.tamtam.nl/) to your composer.json with the following command:  
`composer global config repositories.satis composer https://satis.tamtam.nl`
2. Add dept_gdpr_cookie to your project through:  
`composer require drupal/dept_gdpr_cookie:0.1.0`
3. Enable the module with
`drush en dept_gdpr_cookie -y`
4. goto /admin/config/dept/gdpr/cookies (if you have 'administer nodes' permission) and attach the cookie document + version 
4. the default cookiebar values will be available in templates through 
`<?php print variable_get('cookie_gdpr_version', '1.0');?>` and `<?php print variable_get('cookie_gdpr_document'); ?>`

### Frontend
Please refer to the frontend [Readme.md](https://bitbucket.org/tamtam-nl/tamtam-frontend-shelf/src/e580d3cd0588402061388d6aaa96e74526a0cecf/components/cookiebar/simple/README.md?at=develop&fileviewer=file-view-default)