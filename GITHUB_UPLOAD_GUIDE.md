# 把本项目上传到 GitHub

以下命令以 Windows PowerShell 为例。请把 `你的用户名` 和 `仓库名` 换成自己的信息。

## 1. 安装并检查 Git

安装 Git for Windows 后，打开 PowerShell 检查：

```powershell
git --version
```

能显示版本号即可。

## 2. 在 GitHub 创建空仓库

1. 登录 GitHub，点击右上角 `+`，选择 `New repository`。
2. 填写仓库名，例如 `decimal-base-stack`。
3. 不要勾选 `Add a README file`，因为本地已经有 README。
4. 点击 `Create repository`。
5. 复制仓库地址，例如：

```text
https://github.com/你的用户名/decimal-base-stack.git
```

## 3. 进入项目目录

```powershell
cd "D:\你的路径\decimal-base-stack"
```

用下面的命令确认当前目录中有 `converter.c` 和 `README.md`：

```powershell
Get-ChildItem
```

## 4. 初始化本地 Git 仓库

第一次使用 Git 时，先配置用户名和邮箱：

```powershell
git config --global user.name "你的名字"
git config --global user.email "你的GitHub邮箱"
```

然后在项目目录执行：

```powershell
git init
git add .
git commit -m "feat: add decimal base converter using stack"
git branch -M main
```

## 5. 关联 GitHub 仓库并推送

```powershell
git remote add origin https://github.com/你的用户名/decimal-base-stack.git
git push -u origin main
```

首次推送通常会弹出浏览器登录窗口，按提示授权 GitHub 即可。

## 6. 以后修改代码后再次上传

```powershell
git status
git add .
git commit -m "更新说明"
git push
```

## 常见错误

### `remote origin already exists`

说明之前关联过地址，可以改地址：

```powershell
git remote set-url origin https://github.com/你的用户名/decimal-base-stack.git
```

### `Updates were rejected because the remote contains work`

GitHub 仓库里已经有内容，先拉取再推送：

```powershell
git pull --rebase origin main
git push
```

### 提示输入密码

GitHub 不接受账号登录密码作为 Git 密码。推荐使用 Git Credential Manager 弹出的浏览器登录，或者使用 Personal Access Token。

### `fatal: not a git repository`

当前目录不对或尚未执行 `git init`。先用 `Get-Location` 检查目录，再重新执行初始化步骤。
