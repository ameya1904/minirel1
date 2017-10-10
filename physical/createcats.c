
CreateCats(int argc,char **argv)
{
  int i;
  for ( i = 2; i < argc; i=i+2) {

    printf("arg[%d]=%s\n",i,argv[i] );
  }
 printf("CreateCats \n ");
}
