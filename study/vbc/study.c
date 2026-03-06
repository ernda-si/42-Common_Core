static node *parse_plus(char **s);
static node *parse_multi(char **s);
static node *parse_val(char **s);

node    *parse_expr(char *s)
{
    char *p = s;
    node *ret = parse_plus(&p);
    if (!ret)
        return NULL;
    if (*s) 
    {
        unexpected (*p);
        destroy_tree(ret);
        return (NULL);
    }
    return (ret);
}

static node *parse_val(char **s)
{
    if (isdigit((unsigned char)**s))
    {
        node n = { .type = VAL, .val = **s - '0', .l = NULL, .r = NULL };
        (*s)++;
        return new_node(n);
    }
    if (accept(s, '('))
    {
        node *res = parse_plus(s);
        if (!res)
            return NULL;
        if (!expect(s, ')'))
        {
            destroy_node(res);
            return NULL;
        }
        return res;
    }
    unexpect(**s);
    return NULL;
}

static node *parse_multi(char **s)
{
    node *left = parse_val(s);
    if (!left)
        return NULL;
    while (accept(s, '*'))
    {
        node *right = parse_val(s);
        if (!right)
        {
            destroy_tree(left);
            return NULL;
        }
        node n = { .type = MULTI, .l = left, .r = right };
        left = new_node(n);
        if (!left)
            return NULL;
    }
    return left;
}

static node *parse_plus(char **s)
{
    node *left = parse_multi(s);
    if (!left)
        return NULL;
    while (accept(s, '+'))
    {
        node *right = parse_multi(s);
        if (!right)
        {
            destroy_tree(left);
            return NULL;
        }
        node n = { .type = ADD, .l = left, .r = right };
        left = new_node(n);
        if (!left)
            return NULL;
    }
    return left;
}
