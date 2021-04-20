CC=clang 	# the compiler to be used
CFLAGS=		# flags fot the compiler

# targets
all: c_lang_features binnumbers fnpointers

binnumbers: binary_numbers.c
	$(CC) $(CFLAGS) $^ -o $@

c_lang_features: c_language_features.c
	$(CC) $(CFLAGS) $^ -o $@

fnpointers: function_pointers.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm c_lang_features binnumbers fnpointers

