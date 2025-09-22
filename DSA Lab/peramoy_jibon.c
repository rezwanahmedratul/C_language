// Sir class e evabei 1 line e likhte bolsilo.

char *Replacement(char *str, char *pat, char *newstr) {
    int pos = Indexing(str, pat);
    return Concatenation(Concatenation(SubString(str, 0, pos), newstr),SubString(str, pos + Strlen(pat), Strlen(str) - (pos + Strlen(pat))));
}


char *Deletion(char *str, char *pat) {
    int pos = Indexing(str, pat);
    return Concatenation(SubString(str, 0, pos),SubString(str, pos + Strlen(pat), Strlen(str) - (pos + Strlen(pat))));
}



char *Insertion(char *str, int index, char *pat) {
    return Concatenation(Concatenation(SubString(str, 0, index), pat),SubString(str, index, Strlen(str) - index));
}

