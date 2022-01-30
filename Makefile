format:
	find include lib src -regex '.*\.\(cpp\|hpp\|ipp\|h\)' | xargs clang-format -style=file -i
