#!/bin/bash

brew --version &>/dev/null && echo "brew already installed" || \
( \
	( \
		mv $HOME/.brew $HOME/goinfre/.brew &>/dev/null || \
		rm -rf $HOME/.brew && rm -rf $HOME/goinfre/.brew \
	) && \
	git clone --depth=1 https://github.com/Homebrew/brew $HOME/goinfre/.brew && \
	brew --version &>/dev/null || \
	( \
		echo "export PATH=$HOME/goinfre/.brew/bin:$PATH" >> $HOME/.zshrc && \
		source $HOME/.zshrc \
	) && \
	echo "brew installed" \
)
