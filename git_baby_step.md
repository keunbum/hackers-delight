# Git Baby Step

## Command Note

### init
Initializes a brand new Git repository and begins tracking an existing directory.

### add
Performs 'staging', the first part of that two-step process.

Staging and committing separately gives dvelopers complete control over the history of their project
without changing how they code and work.

```bash
# 'add' with '*' is not recommended.(although there is .gitignore)
$ git add [filename]
```

### commit
Saves the snapshot to the project history and completes the change-tracking process.
In short, a commit functions like taking a photo.
Anything that's been staged with ```git add``` will become a part of the snapshot with ```git commit```.

Git creates a unique ID (a.k.a. the "SHA" of "hash") that allows you to keep record of the specific changes committed
along with who made them and when. Commits usually contain a commit message which is a brief description of what changes were made.

```bash
# if you want detailed comments, just 'git commit'.
$ git commit -m [commit message]
```

### status
Shows the status of changes as untracked, modified, or staged.

### branch
Shows the branches being worked on locally.

### merge
Merges lines of development together. This command is typically used to combine changes made on two distinct branches. For example, a developer would merge
when they want to combine changes from a feature branch into the main branch for deployment.

### pull
Updates the local line of development with updates from its remote counterpart.
Developers use this command if a teammate has made commits to a branch on a remote, and they would like to reflect those changes in their local environment.

```bash
# This is just an example.
# The --set-upstream option might come in handy.
$ git pull --set-upstream [refs-name] [branch-name]
```

### push
Updates remote refs with any commits made locally to a branch.

```bash
# As with pull, -u would be convenient.
$ git push -u [refs-name] [branch-name]
```

### clone
Creates a local copy of a project that already exists remotely.
The clone includes all the project's files, history, and branches.

```bash
# default usage
$ git clone [refs-url]
```

### remote
#### Adding a remote repository
To add a new remote, use the ```git remote add``` command on the terminal,
in the directory your repository is stored at.

The ```git remote add``` command takes two arguments:
* a remote name, for example, ```origin```
* a remote URL, for example, ```https://github.com/user/repo.git```

```bash
# verify remote repos
$ git remote -v
```
For more information, see
"[managing-remote-repositories](https://docs.github.com/en/get-started/getting-started-with-git/managing-remote-repositories)"
or "[Working with Remotes](https://git-scm.com/book/en/v2/Git-Basics-Working-with-Remotes)"
    
### fetch
When you use git fetch, you're adding changes from the remote repository to your local working branch without committing them. **Unlike git pull, fetching allows you to review changes before committing them to your local branch**.

```bash
# if you want synchronize with an upstream repository
$ git fetch upstream
```

### checkout
You can use git *[checkout](https://docs.github.com/en/get-started/quickstart/github-glossary#checkout)* on the command line to create a new branch, change your current working branch to a different branch, or even to switch to a different version of a file from a different branch with ```git checkout [branchname] [path to file]```.


## Reference

### For Markdown
* https://www.makeareadme.com/
* https://www.acmicpc.net/blog/view/1

### For Git
* https://docs.github.com/en/get-started
* https://git-scm.com/docs