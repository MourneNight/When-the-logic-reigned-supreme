### 安装TLP以及图形化界面
```zsh
sudo pacman -S tlp tlp-rdw
paru -S tlpui  #图形化界面
sudo pacman -S smartmontools #显示S.M.A.R.T.数据
```
***ThinkPad需额外安装的***
```zsh
sudo pacman -S tp_smapi acpi_call
```

### 服务设置
```zsh
sudo systemctl enable tlp.service
sudo systemctl enable NetworkManager-dispatcher.service

# 屏蔽以下服务以避免冲突，确保 TLP 无线设备的开关选项可以正确运行
sudo systemctl mask systemd-rfkill.service 
sudo systemctl mask systemd-rfkill.socket
```

### 设置开机启动
```zsh
 sudo tlp start
```

### 其他
1. TLP设置储存于 /etc/tlp.conf