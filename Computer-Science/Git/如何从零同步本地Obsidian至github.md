## Git的设置

***首次配置Git***
1. 需要配置用户名与邮箱
```git
git config --global user.name "name"
git config --global user.email "email"
```
2. 在Github添加SSH
	1. 获取SSH
		```bash
		#进入 ～/.ssh 目录
		mkdir -p ~/.ssh && cd ~/.ssh
		#生成 ed25519 密钥
		ssh-keygen -t ed25519 -C "email"
		#此时 生成了id_ed25519(私钥)  id_ed25519.pub(公钥) 两个文件
		#获取公钥
		cat ~/.ssh/id_ed25519.pub
		```
	2. 将SSH传到Github
	3. 测试SSH连接
	```bash
	ssh -T git@github.com
	#会输出
	#Are you sure you want to continue connecting (yes/no/[fingerprint])?
	#输入yes即可
	```

***Git临时代理***
```bash
#在 export 后加 --global 设置全局

#终端
export http_proxy=http://proyAddress:port
export https_proxy=http://proxyAddress:port

#Git
git config --global http.proxy http://proyAddress:port
git config --global https.proxy http://proyAddress:port

#删除 Git 代理
git config --global --unset http.proxy
git config --global --unset https.proxy
```

***本地初始化Git***
1. 初始化Git
```bash
git init
```
2. 添加远程仓库
```bash
git remote add origin git@github.com:your repository.git
```
3. 首次提交
```bash
git add .
git commit -m "first push"
git branch -M main
git push -u origin main
```



