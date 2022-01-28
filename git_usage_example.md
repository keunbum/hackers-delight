# Git Usage Example
Rather than reckless memorizing, 'Ok.. this is the general flow'.

## Example: Start a new repository and publish it to GitHub.
Create an empty repository.

```bash
# or just 'git init' in the newly created directory
$ git init [repo]

$ cd [repo]

# create some files(ex READMD.md)
# also be done via vi or other editors
$ touch [FILE-NAME]

# git isn't aware of the file, stage it
$ git add [FILE-NAME]

# take a snapshot of the staging area
$ git commit -m [commit message]

# provide the path for the repository you created on github
$ git remote add origin https://github.com/YOUR-USERNAME/YOUR-REPOSITORY-NAME.git

# push changes the github
$ git push -u origin main
```

## Example: Start a new repository and publish it to GitHub.
Resolve merge conflict. Of course, this is just a simple example.

```bash
$ git add [FILE-NAME]
$ git commit
$ git push
.
.
.
(some error messages maybe)
$ git pull
Auto-merging [FILE-NAME]
CONFLICT (content): Merge conflict in [FILE-NAME]
Automatic merge failed; fix conflicts and then commit the result.
$ vi [FILE-NAME]

# Let's edit the file using 3 types of clues:
# 	1. <<<<<<< HEAD
# 	2. =======
# 	3. >>>>>>> new_branch_to_merge_later

$ git add [FILE-NAME]
$ git commit
```

## Models for collaborative development
There are two primary ways people collaborate on GitHub:
1. Shared repository
2. Fork an pull

With a shared repository, individuals and teams are explicitly designated as contributors with read, write, or administrator access.
This simple permission structure, combined with features like protected branches, helps teams progress quickly when they adopt GitHub.


For an open source project, or for projects to which anyone can contribute,
managing individual permissions can be challenging, but a fork and pull model allows anyone who can view the project to contribute.
A fork is a copy of a project under a developer's personal account.
Every developer has full control of their fork and is free to implement a fix or a new feature.
Work completed in forks is either kept separate, or is surfaced back to the original project via a pull request.
There, maintainers can review the suggested changes before they're merged.
For more information, see "[Contribution to projects](https://docs.github.com/en/get-started/quickstart/contributing-to-projects)"


## Reference
* https://docs.github.com/en/get-started/using-git/about-git