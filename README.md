# Hacker's Delight
codes to solve this and that algorithm problem..

## Command Note
I don't know why I'm writing the Git commands here...

### add

```bash
# 'add' with '*' is not recommended.(although there is .gitignore)
git add [filename]
```

### commit
a *[commit](https://docs.github.com/en/get-started/quickstart/github-glossary#commit)* is like a snapshot of all the files in your project at a particular point in time.

```bash
# if you want detailed comments, just 'git commit'.
git commit -m [commit message]
```

### push

```bash
# you'll need to know the exact meaning of '-u' someday, that of the other arguments as well...
git push -u origin main
```

### clone
a *[clone](https://docs.github.com/en/get-started/quickstart/github-glossary#clone)* is a copy of a repository that lives on local.

```bash
# default usage
$ git clone [url]
```

### remote

```bash
# if you want to check where it is based
$ git remote -v

# if you want to add upstream
$ git remote add upstream [url]
```
    
### fetch
When you use git fetch, you're adding changes from the remote repository to your local working branch without committing them. **Unlike git *[pull](https://docs.github.com/en/get-started/quickstart/github-glossary#pull)*, fetching allows you to review changes before committing them to your local branch**.

```bash
# if you want synchronize with an upstream repository
$ git fetch upstream
```

### checkout
You can use git *[checkout](https://docs.github.com/en/get-started/quickstart/github-glossary#checkout)* on the command line to create a new branch, change your current working branch to a different branch, or even to switch to a different version of a file from a different branch with ```git checkout [branchname] [path to file]```.

### merge
Merging takes the changes from one branch (in the same repository or from a fork), and applies them into another. This often happens as a "pull request" (which can be thought of as a request to merge), or via the command line. A merge can be done through a pull request via the GitHub.com web interface if there are no conflicting changes, or can always be done via the command line.


## Reference

* https://www.makeareadme.com/
* https://www.acmicpc.net/blog/view/1

