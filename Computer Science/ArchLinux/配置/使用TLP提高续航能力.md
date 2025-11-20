### 安装TLP以及图形化界面
```zsh
sudo pacman -S tlp tlp-rdw
paru -S tlpui  #图形化界面
```

### 服务设置
```zsh
sudo systemctl enable tlp.service
sudo systemctl enable NetworkManager-dispatcher.service
sudo systemctl mask systemd-rfkill.service 
# 屏蔽以下服务以避免冲突，确保 TLP 无线设备的开关选项可以正确运行
sudo systemctl mask systemd-rfkill.socket
```

### 设置开机启动
```zsh
 sudo tlp start
```

