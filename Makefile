SUBDIRS = client server
all:
	@list='$(SUBDIRS)'; for subdir in $$list; do /
	echo "Making in $$list"; /
	(cd $$subdir && make); /
	done;
.PHONY: clean
clean:
	@list='$(SUBDIRS)'; for subdir in $$list; do /
	echo "Clean in $$subdir"; /
	(cd $$subdir && make clean); /
	done



