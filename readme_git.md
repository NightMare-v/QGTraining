### Git的语法格式的初步学习（Linux的命令)



##### 1.对于更改当前操作页面的目录

```linux
$ cd F:git_learning
```



##### 2.对于在操作页面的目录中建立仓库 Linux `mkdir`（英文全拼：make directory）命令用于创建目录。

```linux
$ mkdir git_learning
```



##### 3.对于显示整个路径名`pwd` (Print Working Directory)

```linux
$ pwd
/c/Users/Nightmare_v
```



##### 4.对于`git init` 命令用于在目录中创建新的 Git 仓库。



##### 5.对于查看结果 `git suatus` 用于让我们时刻掌握仓库当前的状态，此命令输出告诉我们，其中被修改过了，但还没有准备提交的修改。

```linux
$ git status
On branch master
Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        modified:   re.md

no changes added to commit (use "git add" and/or "git commit -a")

```



##### 6.对于查看具体修改了什么内容，`git diff` 查看 difference

```linux
$ git diff
diff --git a/re.md b/re.md
index e69de29..7ec9a4b 100644
--- a/re.md
+++ b/re.md
@@ -0,0 +1 @@
+aa
\ No newline at end of file

```

##### 小结
1.要随时掌握工作区的状态，使用`git status`命令。
2.如果`git status`告诉你有文件被修改过，用`git diff`可以查看修改内容。




##### 7.对于把一个文件放到Git仓库只需要两步。
第一步，用命令`git add`告诉Git，把文件添加到仓库。
第二步，用命令`git commit`告诉Git，把文件提交到仓库。git commit命令执行成功后会告诉你，`1 file changed`：1个文件被改动（我们新添加的文件）；`1 insertions`：插入了一行内容（文件有一行内容）。
```linux
$ git commit -m "write"
[master 1fc3355] write
 1 file changed, 1 insertion(+)

```
##### 小结
现在总结一下今天学的两点内容：
初始化一个Git仓库，使用`git init`命令。
添加文件到Git仓库，分两步：
使用命令`git add <file>`，注意，可反复多次使用，添加多个文件
使用命令`git commit -m <message>`，完成。



##### 8.版本控制系统肯定有某个命令可以告诉我们历史记录，在Git中，我们用`git log`命令查看.
```linux
$ git log
commit 1fc3355a3f41b98ec420f76c15cbe327da13e0b4 (HEAD -> master)
Author: NightMare-v <1813947408@qq.com>
Date:   Sun Mar 28 12:13:27 2021 +0800

    write

commit 3a53e730dc4077f1e57acf33ceac7c293e87b0f1
Author: NightMare-v <1813947408@qq.com>
Date:   Sun Mar 28 11:55:41 2021 +0800

    aa

```


##### 9.对于回退版本,首先，Git必须知道当前版本是哪个版本，在Git中，用`HEAD`表示当前版本，也就是最新的提交，上一个版本就是`HEAD^`，上上一个版本就是`HEAD^^`，当然往上100个版本写100个^比较容易数不过来，所以写成`HEAD~100`。使用`git reset --hard HEAD^`返回上个版本的内容

```linux
$ git reset --hard HEAD^
HEAD is now at 3a53e73 aa

```
版本在此返回找回方式。只要上面的命令行窗口还没有被关掉，你就可以顺着往上找，找到那个append GPL的commit id是1fc3355...，于是就可以指定回到未来的某个版本。版本号没必要写全，前几位就可以了，Git会自动去找。(暂且是指针的选择位置的改变因而寻找速度快)
```linux
$ git reset --hard 1fc3355
HEAD is now at 1fc3355 write
```
查看历史命令
```linux
$ git reflog
1fc3355 (HEAD -> master) HEAD@{0}: reset: moving to 1fc3355
3a53e73 HEAD@{1}: reset: moving to HEAD^
1fc3355 (HEAD -> master) HEAD@{2}: commit: write
3a53e73 HEAD@{3}: commit (initial): aa
```
##### 小结
1.HEAD指向的版本就是当前版本，因此，Git允许我们在版本的历史之间穿梭，使用命令`git reset --hard commit_id`。
2.穿梭前，用`git log`可以查看提交历史，以便确定要回退到哪个版本。
3.要重返未来，用`git reflog`查看命令历史，以便确定要回到未来的哪个版本。



##### 10.我们把文件往Git版本库里添加的时候，是分两步执行的：
第一步是用git add把文件添加进去，实际上就是把文件修改添加到暂存区；
第二步是用git commit提交更改，实际上就是把暂存区的所有内容提交到当前分支。
因为我们创建Git版本库时，Git自动为我们创建了唯一一个master分支，所以，现在，git commit就是往master分支上提交更改。
你可以简单理解为，需要提交的文件修改通通放到暂存区，然后，一次性提交暂存区的所有修改。



##### 11.你可以发现，Git会告诉你，`git checkout -- file`可以丢弃工作区的修改：
命令`git checkout -- file`意思就是，把file文件在工作区的修改全部撤销，这里有两种情况：
1.一种是file自修改后还没有被放到暂存区，现在，撤销修改就回到和版本库一模一样的状态；
2.一种是file已经添加到暂存区后，又作了修改，现在，撤销修改就回到添加到暂存区后的状态。
总之，就是让这个文件回到最近一次`git commit`或`git add`时的状态。

##### 小结
场景1：当你改乱了工作区某个文件的内容，想直接丢弃工作区的修改时，用命令git checkout -- file。
场景2：当你不但改乱了工作区某个文件的内容，还添加到了暂存区时，想丢弃修改，分两步，第一步用命令`git reset HEAD <file>`，就回到了场景1，第二步按场景1操作。
场景3：已经提交了不合适的修改到版本库时，想要撤销本次提交，参考版本回退一节，不过前提是没有推送到远程库



##### 12. 小提示：先手动删除文件，然后使用`git rm <file>`和`git add<file>`效果是一样的。
另一种情况是删错了，因为版本库里还有呢，所以可以很轻松地把误删的文件恢复到最新版本：

`$ git checkout -- test.txt`

git checkout其实是用版本库里的版本替换工作区的版本，无论工作区是修改还是删除，都可以“一键还原”。

##### 注意：从来没有被添加到版本库就被删除的文件，是无法恢复的！
##### 小结
命令`git rm`用于删除一个文件。如果一个文件已经被提交到版本库，那么你永远不用担心误删，但是要小心，你只能恢复文件到最新版本，你会丢失最近一次提交后你修改的内容。

##### 13.从现在起，只要本地作了提交，就可以通过命令：
`$ git push origin master`

把本地master分支的最新修改推送至GitHub

##### 小结
要关联一个远程库，使用命令`git remote add origin git@server-name:path/repo-name.git`
`git remote add origin https://github.com/NightMare-v/night_for_v.git`

`git remote add origin git@github.com:NightMare-v/night_for_v.git`

`git branch -M main `
`git push -u origin main`
关联一个远程库时必须给远程库指定一个名字，origin是默认习惯命名；
关联后，使用命令`git push -u origin master`第一次推送master分支的所有内容；
此后，每次本地提交后，只要有必要，就可以使用命令`git push origin master`推送最新修改；



##### 14.clone远程仓库到本地库，示例代码如下：
`$ git clone git@github.com:NightMare-v/gitskills.git`

要克隆一个仓库，首先必须知道仓库的地址，然后使用`git clone`命令克隆。
Git支持多种协议，包括`https`，但`ssh`协议速度最快。



##### 15.分支的使用
###### 查看分支：git branch
###### 创建分支：`git branch <name>`
###### 切换分支：`git checkout <name>`或者`git switch <name>`
###### 创建+切换分支：`git checkout -b <name>`或者`git switch -c <name>`
###### 合并某分支到当前分支：`git merge <name>`
###### 删除分支：`git branch -d <name>`