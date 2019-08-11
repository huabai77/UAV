下载所有安装包到一个目录，解压产生: mixr, mixr-data, mixr-examples, mixr-3rdparty    

Visual Studio Community 2019    
生成mixr    
生成example    
运行mixr-examples目录下的make-edl.cmd文件    
完成    

说明：
如果使用19.0x版本的3rd party library+18.01版本的mixr，由于版本不匹配，需要修改部分路径设置：
首先修改3rd库的连接路径，将目录vs2017-x32改为vs2017-32    
接着将mainIgViewer的C++连接器->常规中的附加库目录中osgPlugins-3.4.1改为osgPlugins-3.6.3    
接着将mainIgViewer的C++连接器->输入的附加依赖项中的输入路径中的所有osg131改为osg158    
接着将mainIgViewer的C++连接器->输入的附加依赖项中的输入路径中的所有ot20改为ot21    
