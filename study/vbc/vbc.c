node    *parse_val(char s);
node    *parse_multi(char s);
node    parse_plus(char **s);

nodeparse_expr(char s)
{
    node ret = parse_plus(s);
    if(!ret)
        return NULL;
    if(s)
    {
        unexpected(s);
        destroy_tree(ret);
        return (NULL);
    }
    return(ret);
}

node parse_val(char s)
{
    if(isdigit((unsigned char)s))
    {
        node n = {.type = VAL,.l = NULL,.r = NULL,.val = **s - '0'};
        (s)++;
        return(new_node(n));
    }
    if(accept(s,'('))
    {
        node res = parse_plus(s);
        if(!res)
            return(NULL);
        if(!expect(s,')'))
        {
            destroy_tree(res);
            return(NULL);
        }
        return(res);
    }
    unexpected(**s);
    return(NULL);
}

nodeparse_multi(char s)
{
    node left = parse_val(s);
    if(!left)
        return (NULL);
    while(accept(s,''))
    {
        node right = parse_val(s);
        if(!right)
        {
            destroy_tree(left);
            return(NULL);
        }
        node n = {.type = MULTI,.l = left,.r = right};
        left = new_node(n);
        if(!left)
            return(NULL);
    }
    return(left);
}

nodeparse_plus(char s)
{
    node left = parse_multi(s);
    if(!left)
        return(NULL);
    while(accept(s,'+'))
    {
        noderight = parse_multi(s);
        if(!right)
        {
            destroy_tree(left);
            return(NULL);
        }
        node n = {.type = ADD,.l = left,.r = right};
        left = new_node(n);
        if(!left)
            return(NULL);
    }
    return(left);
}
