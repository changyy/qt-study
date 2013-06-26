TEMPLATE = subdirs
include(build.settings)
CONFIG += ordered
EXTRAS_LIBS += main core-service

for(dir, EXTRAS_LIBS)
{ 
	exists($$dir)
	{
		SUBDIRS += $$dir
	}
}
