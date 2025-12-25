***来自https://www.reddit.com/r/neovim/comments/15j87k7/lazyvim_setting_transparent_background/***

1. 创建一个 `~/.config/nvim/lua/plugins/colorscheme.lua`
2. 包含:
```
return {
{
  "folke/tokyonight.nvim",
  opts = {
    transparent = true,
    styles = {
      sidebars = "transparent",
      floats = "transparent",
    },
  },
},
}
```
