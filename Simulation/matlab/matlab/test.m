function time = test()

time = [1:100];
count = 1;
figure;
while (count <= 100)
    fprintf(1,'%d \n',count);
    time(count) = mypid(120 * count,0,400,40,22,'b',0);    
    fprintf(1,'\n\n');
    count = count + 1;
end
figure;
plot(time);