#!/bin/bash

git_seek_and_replace()
{
  if [ "$#" -ne 2 ]; then
      echo "Usage: git_seek_and_replace needle substitutor" >&2
      return 1
  fi

  git diff-index --quiet HEAD --
  check_unstaged=$?
  if [ $check_unstaged -ne 0 ]; then
      echo "git_seek_and_replace cannot be executed when there is unstaged changes"
      return 1
  fi
  git grep -l $1 | xargs sed -i s/$1/$2/g
}

error_print()
{
    cowsay -h &> /dev/null
    has_cowsay=$?

    ponysay -h &> /dev/null
    has_ponysay=$?

    if [ $has_ponysay -eq 0 ]; then
	ponysay --pony derpysad $1
    elif [ $has_cowsay -eq 255 ]; then
	echo $1 | cowsay -d
    else
	tput setaf 1
	echo $1
	tput sgr0
    fi
}

