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
$ touch [file]

# git isn't aware of the file, stage it
$ git add [file]

# take a snapshot of the staging area
$ git commit -m [commit message]

# provide the path for the repository you created on github
$ git remote add origin https://github.com/YOUR-USERNAME/YOUR-REPOSITORY-NAME.git

# push changes th github
$ git push --set-upstream origin main
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