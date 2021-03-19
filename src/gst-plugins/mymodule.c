#include <config.h>
#include <gst/gst.h>

#include "gstcustommixer.h"

static gboolean
init (GstPlugin *plugin)
{
    // gst_my_module_plugin_initからkms_custom_mixer_plugin_initに変更
    if (!kms_custom_mixer_plugin_init (plugin))  
      return FALSE;

  return TRUE;
}

GST_PLUGIN_DEFINE (GST_VERSION_MAJOR, GST_VERSION_MINOR,
    mymodule,
    "Filter documentation",
    init, VERSION, GST_LICENSE_UNKNOWN, "PACKAGE_NAME", "origin")
