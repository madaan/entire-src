BEGIN{
printf("\nSG AWK");
}
{
if(NR%2==0)
{
print $0 >"f1";
}
else
{
print $0>"f2";
}
}

