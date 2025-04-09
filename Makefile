CC = cc
CFLAGS = -Wall -Wextra -Werror
SERVER_NAME = server
CLIENT_NAME = client
SRC_SERVER = server.c
SRC_CLIENT = client.c
OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

all: $(SERVER_NAME) $(CLIENT_NAME)

$(CLIENT_NAME): $(OBJ_CLIENT)
	$(CC) $(CFLAGS) $(OBJ_CLIENT) -o $(CLIENT_NAME)

$(SERVER_NAME): $(OBJ_SERVER)
	$(CC) $(CFLAGS) $(OBJ_SERVER) -o $(SERVER_NAME)

clean:
	rm -f $(OBJ_SERVER) $(OBJ_CLIENT)

fclean: clean
	rm -f $(SERVER_NAME) $(CLIENT_NAME)

re: fclean all

.PHONY: clean

.SECONDARY: $(OBJ_SERVER) $(OBJ_CLIENT)
