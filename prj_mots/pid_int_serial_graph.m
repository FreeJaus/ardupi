priorPorts = instrfind; % finds any existing Serial Ports in MATLAB
delete(priorPorts);

s1=serial('COM3','Baudrate',38400);
fopen(s1);
ch = 3;
buff=zeros(1,ch);
str='';
sen=zeros(1,ch);
j=1;
x=0;

while(1)
 str=fscanf(s1);
 sen=str2num(str);
 for k=1:ch
  buff(j,k)=sen(k);
 end;
 x(j)=j;
 
if (j<200)
 j=j+1;
else
 buff(1:199,:)=buff(2:200,:);
end;
 
 plot(buff);
 drawnow;
end;

fclose(s1);
delete(s1);
clear s1;