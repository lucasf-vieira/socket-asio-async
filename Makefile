CLIENT := ./client
SERVER := ./server

.PHONY: all clean

all:
	$(MAKE) -C $(CLIENT)
	$(MAKE) -C $(SERVER)

clean:
	$(MAKE) -C $(CLIENT) clean
	$(MAKE) -C $(SERVER) clean
	rm -rf *.out
