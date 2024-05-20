# 说明


1. 安装conan并初始化本地profile，可以参考本仓库的 profiles 目录。

2. 构建

        conan create . --profile default -s build_type=Debug --build missing
        conan create . --profile default -s build_type=Release --build missing
        conan create . --profile ios -s build_type=Debug --build missing
        conan create . --profile ios -s build_type=Release --build missing

3. 上传

	    conan upload poco/1.13.3-c14p2 -r=youle

4. 检查上传到remote的结果

        conan search poco -r=youle
        conan list poco/*:* -r=youle

5. 清除本地构建的缓存

        conan remove poco -c
        conan list poco/*:*

6. 安装到本地

        conan install --requires=poco/1.13.3-c14p2 -r=youle -s build_type=Debug
        conan install --requires=poco/1.13.3-c14p2 -r=youle -s build_type=Release
        conan list poco/1.13.3-c14p2:*

7. 使用参考 `test_package/conanfile.py` & `test_pacakage/CMakeLists.txt`
        
## 需要查问题时，拆分`conan create`的步骤手动执行：


    conan install . --profile default -s build_type=Debug --build missing
    conan build . --profile default -s build_type=Debug
    conan test test_package poco/1.13.3-c14p2 -s build_type=Debug

