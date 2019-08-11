下载地址：http://www.mixr-platform.org/doku.php?id=downloads:downloads
最新发布版本18.01
下载所有安装包到一个目录，解压产生: mixr, mixr-data, mixr-examples, mixr-3rdpartysrc

在mixr目录下执行命令设置环境变量：
source setenv.sh

安装第三方依赖（参考mixr-3rdpartysrc/README.md）
执行sudo apt install安装依赖包：libfreetype6, libfreetype6-dev, freeglut3, freeglut3-dev, libftgl2, libftgl-dev, libgdal-dev
安装编译工具(sudo apt install): autogen, automake, libtool, libtool-bin, cmake
安装mixr-3rdpartysrc下的第三方包：
source build_libs.sh
help
install_all
安装完成会出现mixr-3rdparty目录

编译mixr:
进入mixr/src目录，运行make

编译mixr-examples:
修改mixr-examples/makedefs，把osgPlugins-3.4.1改为osgPlugins-3.6.3
在mixr-examples目录下运行：
source setenv.sh
make

生成mixr代码文档：
安装文档生成工具(sudo apt install): doxygen doxygen-gui graphviz graphviz-doc
修改doxygen配置文件：
在mixr/doc目录下修改文件doxygenGraphics.cfg，设置INPUT参数值为mixr/src目录的路径，保存
在mixr/doc目录下运行命令：
doxygen doxygenGraphics.cfg
在doc目录下会生成一个html目录，打开index.html查看生成的文档
