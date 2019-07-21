Example Data(mixr-data), 3rd party library(mixr-3rdparty): 19.0x版    
Framework(mixr), Examples(mixr-examples): 18.01版    
下载所有安装包到一个目录，解压产生: mixr, mixr-data, mixr-examples, mixr-3rdparty    

Visual Studio Community 2019    
mixr生成成功
example生成失败
首先修改3rd库的连接路径，将目录vs2017-x32改为vs2017-32
接着将mainIgViewer的C++连接器->常规中的附加库目录中osgPlugins-3.4.1改为osgPlugins-3.6.3
接着将mainIgViewer的C++连接器->输入的附加依赖项中的输入路径中的所有osg131改为osg158
接着将mainIgViewer的C++连接器->输入的附加依赖项中的输入路径中的所有ot20改为ot21
运行mixr-examples目录下的make-edl.cmd文件
完成
