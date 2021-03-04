# WaveRush
[![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0)
![Build](https://github.com/OhhhZenix/WaveRush/actions/workflows/build.yml/badge.svg)
[![Discord Chat](https://img.shields.io/discord/308323056592486420.svg)](https://discord.gg/9yV8pPZXfY) <br>
 A simple game made in C++

# How to work on
### Step 1: Fork the repository
In https://github.com/OhhhZenix/WaveRush, look for the fork icon in the top right. Click it to create a fork of the repository (repo).

Basically, this will copy the repo into your GitHub account url. It should create a copy at https://github.com/YOURUSERNAME/website, where `YOURUSERNAME` is replaced with exactly that.

Note that this is a copy on the GitHub website and not on your computer yet.

### Step 2: Clone your online repo onto your local computer

For git beginners, this will make a third copy of the repo on your local desktop.

First, navigate to the folder will you want to contain the project.

Next, in your shell, navigate and run the following command:

```bash
git clone --recursive https://github.com/YOURUSERNAME/WaveRush.git
```

You should now have a new folder called `WaveRush`. Verify this by going into the directory:

```bash
cd WaveRush
```

Next, verify that youe local repo is pointing to the correct `origin` url (That is, the forked repo on your GitHub account):
```bash
git remote -v
```

You should see `fetch` and `push` urls with links to your forked repo under your account (Ex: `https://github.com/YOURUSERNAME/WaveRush.git`). You are all set to make working changes to the project on your local machine.

However, we still need a way to keep our local repo up to date with the github servers. To do so, you must add a remote upstream to incorporate changes made while you are also working on your local repo. Run the following command to add a remote upstream and update your local repo with recent changes from the GitHub servers:

```bash
git remote add upstream https://github.com/OhhhZenix/WaveRush.git
git fetch upstream
```

After adding the remote upstream, you should now see it if you run `git remote -v` again:
```bash
origin https://github.com/YOURUSERNAME/WaveRush.git (fetch)
origin https://github.com/YOURUSERNAME/WaveRush.git (push)
upstream https://github.com/OhhhZenix/WaveRush.git (fetch)
upstream https://github.com/OhhhZenix/WaveRush.git (push)
```

### Step 3: Edit and run the code

First, make sure you have [Visual Studio Code (vscode)](https://code.visualstudio.com/download) installed.

Next, open vscode and click on the `File` on the top left, then `Open Folder...`, navigate to your local repo and click `Select Folder` or `Open`.

On the bottom of the window in vscode, there should be a play icon, click on it, you should see the program run.

**Note**: The first time you build the project it will take a while, but afterwards it should be quicker.

### Step 4: Commiting code

Before you write any code, create a new branch for each issue you work on. This simplifies the process of merging to the main branch and isolate different issues.

**Note**: You MUST do this everytime you work on an issue.

a) Check current branch

The `git branch` command will let you know which branch you're in, and what branch names are already in use.

```bash
git branch
```

You will see a list of all your branches. There be a star (`*`) next to the branch that you are in currently. By default you should start on the `dev` branch.

**Note**: When you work on future issues, you MUST always be in the `dev` branch when creating a new branch.

If you are not currently in the `dev` branch, run the following command to return to it:

```bash
git checkout dev
```

b) Create a new branch where you will work on your issue

The `git checkout` command will create and change to a new branch, where you will do the work on your issue. In git, the checkout command lets you navigate between different branches. Using the `-b` flag, you can create a new branch and switch into it.

To create a new issue branch, and switch to it run the following command. Replace `branch-name` with name of your branch (Remember you cannot have spaces).

```bash
git checkout -b branch-name
```

c) Push your changes to the GitHub website

So you've finished working on your issue, great!

Now, you get to push your code to the GitHub website.

First, stage all of your changes. You can stage singular files by just replacing `.` with the filename, or use `.` to stage all of the files that have been added or changed.

```bash
git add .
```

Run `git status` to make sure everything you need gets staged:

```bash
git status
```

Great, now that you have staged your changes, you can commit them:

```bash
git commit -m "insert message here"
```

### Step 5: Check upstream before you push

Before you push your local commits to your repo, check to see if anything has changed. The `git fetch` will check remote repos for changes without altering your local repository:

```bash
git fetch upstream
```

a) No changes in the upstream repo

If there was no output, then there have not been any changes in the main repo since last time you fetched. So, you can safely push your local commits to your fork.

If you just run `git push`, you will be prompted to create a new branch in your GitHub repo. The more complete command below will create a new branch on your fork:

```bash
git push --set-upstream origin branch-name
```

b) Conflicting changes in the upstream repo

When you fetch the upstream repo, you might see output like this:

```bash
Fetching upstream
remote: Enumerating objects: 11, done.
remote: Counting objects: 100% (11/11), done.
remote: Compressing objects: 100% (7/7), done.
remote: Total 11 (delta 5), reused 7 (delta 4), pack-reused 0
Unpacking objects: 100% (11/11), 8.25 KiB | 402.00 KiB/s, done.
```

If this shows, then feel free to cower in fear or ask for help in the discord server. 