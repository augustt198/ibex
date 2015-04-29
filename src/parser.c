#include "parser.h"

int getIndentationLevel(char *line);

list_t *Blockify(char **lines, int len, int *pos, int lvl) {
    list_t *list = malloc(sizeof(list_t));
    list_init(list);
    list_attributes_copy(list, list_meter_uint64_t, 0);

    while (*pos < len) {
        int indent = getIndentationLevel(lines[*pos]);
        if (indent == lvl) {
            BlockEntry *entry = malloc(sizeof(BlockEntry));
            entry->type = LINE;
            entry->line = lines[*pos];
            list_append(list, entry);
            *pos += 1;

        } else if (indent == lvl + 4) {
            list_t *sub_list = Blockify(lines, len, pos, indent);
            BlockEntry *entry = malloc(sizeof(BlockEntry));
            entry->type  = BLOCK;
            entry->block = sub_list;
            list_append(list, entry);
        } else {
            break;
        }
    }

    return list;
}

int getIndentationLevel(char *line) {
    int len = strlen(line);

    int i = 0;
    for (; i < len && line[i] == ' '; i++);

    return i;
}
