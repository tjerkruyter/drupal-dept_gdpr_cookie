<?php
function dept_gdpr_admin_cookie_settings_form()
{
    $form = [];


    $form['cookie_gdpr_version'] = [
        '#type'          => 'textfield',
        '#title'         => t('Version'),
        '#default_value' => variable_get('cookie_gdpr_version', '1.0'),
        '#maxlength'     => 10,
        '#required'      => true,
    ];

    $form['cookie_gdpr_document'] = [
        '#title'             => t('Document'),
        '#type'              => 'managed_file',
        '#description'       => t('Please upload GDPR document. Allowed extension: PDF'),
        '#default_value'     => variable_get('cookie_gdpr_document', ''),
        '#upload_location'   => 'public://documents/',
        '#upload_validators' => [
            'file_validate_extensions' => ['pdf'],
        ],
    ];

    $form['#submit'][] = 'dept_gdpr_cookie_form_file_save';


    return system_settings_form($form);
}

function dept_gdpr_admin_cookie_settings_form_validate($form, &$form_state)
{
    if (empty($form_state['values']['cookie_gdpr_document']) || $form_state['values']['cookie_gdpr_document'] === 0) {
        form_set_error('cookie_gdpr_document', t('The field %field is required.', ['%field' => 'cookie_gdpr_document']));
    }
}

function dept_gdpr_cookie_form_file_save($form, &$form_state)
{
    global $user;
    // Ensure uploaded files are permanent

    // Load the file via file.fid.
    $file = file_load($form_state['values']['cookie_gdpr_document']);

    if ($file === false) {
        form_set_error('cookie_gdpr_document', t('Could not process %field upload.', ['%field' => 'cookie_gdpr_document']));
    }

    // Change status to permanent.
    $file->status = FILE_STATUS_PERMANENT;
    // Save.
    file_save($file);
    // Record that the module is using the file.
    file_usage_add($file, 'dept_gdpr', 'user', $user->uid);
}