G = load('graph.txt')
 
V = [size(G,1),3];


for i=1:1:size(G,1)
   
    x = cos((2*pi*i) / size(G,1));
    y = sin((2*pi*i) / size(G,1));
    
    V(i,2) = x;
    V(i,3) = y;   

endfor

   
   
   
figure(42);
title("Graph representation");
plot(V(:,2),V(:,3),'*b');  % graph vertex
hold on
orden=[];                          
for i=1:1:size(G,1)
   orden(1,i)=sum(G(i,:)); 
end
 
Y=[];
G=triu(G); 
for i=1:1:size(G,1)   %Create the paths
    for j=1:1:size(G,1)
         
        if G(i,j)==1
          Y=[V(i,2:3);
             V(j,2:3)];
          
          plot(Y(:,1),Y(:,2),'-r')
          hold on
        end
    end    
end
 


A=G;
D=[];
n=0;
if a==0 || a==2
 
   for i=1:1:size(G,1)   %Create the paths by running through the graph
    for j=1:1:size(G,1)
         
        if G(i,j)==1
            n=n+1;
            D(n,:)=[i j];  
        end
    end    
   end 
end

w=0; %path counter
X=zeros(size(D,1)+1); %path counter matrix 
 
F=[];   %array that stores the route
gu=D;
while D~=0 
 
   o=randi(size(D,1),1); 
    
   F=D(o,:);   
     
   D(o,:)=[];  
while F(1,1)~=F(1,end)
     
   a=D==F(1,end); %search the paths that ends in F
   a=a(:,1)+a(:,2); 
   a=logical(a); %store all the possible paths
   M=D(a,:); 
     
    if M==0 
      if size(F,2)==2
       F=[F(1,2) F(1,1)]; 
       a=D==F(1,end); 
       a=a(:,1)+a(:,2); 
       a=logical(a);
       M=D(a,:);
        
      end
    end
  if M~=0   
    r=randi(size(M,1),1);  %choses a random path to verify
    
        if F(1,end)==M(r,1)  
             F(1,end+1)=M(r,2);  
        else
             F(1,end+1)=M(r,1);
        end
    
  if F(1,1)~=F(1,end)  
%% deletes the paths    
      
    k=0;
    for i=1:1:size(D,1) %traverses the path matrix
        
        if a(i,1)==1  
          k=k+1;  
            if r==k   
                D(i,:)=[];  
                break   
            end
        end
    end
     
          
  else       
      
    k=0;
    for i=1:1:size(D,1)  
        
        if a(i,1)==1  
          k=k+1;  
            if r==k   
                D(i,:)=[];  
                break   
            end
        end
    end
     

      w=w+1;
      gu=D;  
      X(w,1:size(F,2))=F;
       
 
       
  end 
     
  else   % if there are no more paths
        
       w=w+1;  
      
      gu=D;  
       X(w,1:size(F,2))=F;
      
  end
end
   if F(1,1)~=F(1,end) 
       
      break
   end
 
end
 
%graph printing
 
for i=1:1:w   
    a=X(i,:)>0; %look out for the paths there are different than 0 - that have edges -
    F=X(i,a); 
     
   for n=1:1:size(F,2)-1   % print the paths
       
          Y=[V(F(1,n),2:3);
             V(F(1,n+1),2:3)];
          figure(i)
          plot(Y(:,1),Y(:,2),'-b')
          hold on
          
   end 
    plot(V(:,2),V(:,3),'*r')  % plots the vertices
    hold on
end
 
% verifies the edges
 
i=0;
j=0;
while i<=w
    i=i+1;
    a=X(i,:)>0; 
    T=X(i,a);  
    j=0;
   while j<size(T,2)  
      j=j+1 
     a=X(:,1)==X(i,j);  
     a(i,1)=0;    
      
     if sum(a)~=0   
       b=X(a,:); 
       d=b>0;  
       B=b(d);  
        
       S1=T(1,1:j-1) 
       S2=T(1,j+1:end)
       F=[S1 B S2]  
        
       X(i,1:size(F,2))=F;  
       X(a,:)=[];  
       i=1;
       a=X(i,:)>0; 
       T=X(i,a);  
     end       
   end
end
 
 
b=X(1,:); % get the paths 
d=b>0;  %delete the 0's
F=b(d)
if w~=1
for n=1:1:size(F,2)-1   %generate the paths with ends in the graph
       
          Y=[V(F(1,n),2:3);
             V(F(1,n+1),2:3)];
          figure(1000+i)
          plot(Y(:,1),Y(:,2),'-b')
          hold on
          
end 
   plot(V(:,2),V(:,3),'*r')  % graph vertex
   title("graph representation")
end
