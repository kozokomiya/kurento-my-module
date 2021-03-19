#ifndef _GST_MY_MODULE_H_
#define _GST_MY_MODULE_H_

#include <gst/video/gstvideofilter.h>

G_BEGIN_DECLS

#define GST_TYPE_MY_MODULE   (gst_my_module_get_type())
#define GST_MY_MODULE(obj)   (G_TYPE_CHECK_INSTANCE_CAST((obj),GST_TYPE_MY_MODULE,GstMyModule))
#define GST_MY_MODULE_CLASS(klass)   (G_TYPE_CHECK_CLASS_CAST((klass),GST_TYPE_MY_MODULE,GstMyModuleClass))
#define GST_IS_MY_MODULE(obj)   (G_TYPE_CHECK_INSTANCE_TYPE((obj),GST_TYPE_MY_MODULE))
#define GST_IS_MY_MODULE_CLASS(klass)   (G_TYPE_CHECK_CLASS_TYPE((klass),GST_TYPE_MY_MODULE))
typedef struct _GstMyModule GstMyModule;
typedef struct _GstMyModuleClass GstMyModuleClass;
typedef struct _GstMyModulePrivate GstMyModulePrivate;

struct _GstMyModule
{
  GstVideoFilter base;
  GstMyModulePrivate *priv;
};

struct _GstMyModuleClass
{
  GstVideoFilterClass base_my_module_class;
};

GType gst_my_module_get_type (void);

gboolean gst_my_module_plugin_init (GstPlugin *plugin);

G_END_DECLS

#endif /* _GST_MY_MODULE_H_ */
