typedef char *string_t;
struct foo { string_t str; int i; };
void print_data( const type_t *type, const void *data )
{
	switch( type->type ) {
		case TYPE_TYPEDEF:
			assert(strcmp(type->name, "string_t") == 0);
			printf("(%s) \"%s\"\n", type->name,
			       *((const string_t *) data));
			break;
		case TYPE_INT:
			printf("(%s) %d\n", t->name,
			       *((const int *) data));
			break;
		case TYPE_STRUCT:
			const struct_t *s = (const struct_t *) type;
			printf("(%s) {\n", s->name);
			for( size_t i = 0; i < s->nfields; i++ ) {
				const field_t *f = &s->fields[i];
				printf("\t.%s = ", f->name);
				print_data(f->referent, data + f->offset);
			}
			printf("}\n");
			break;
		default:
			assert(false);
	}
}
int main()
{
	struct foo bar = {
		.str = "Hello World!",
		.i = 6666
	};
	const type_t *t = get_type("struct foo");
	print_data(t, &bar);
	release_type(t);
}
