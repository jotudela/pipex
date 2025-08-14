# 🚀 INTRODUCTION

---

The `pipex` project at 42 school challenges students to craft a program emulating the intricacies of shell command pipelines in the C language.

This endeavor necessitates a deep comprehension of process creation, manipulation, and input/output redirection. Students are tasked with
orchestrating a sequence of commands, efficiently directing the output of one command as the input for the next.

The project not only hones skills in managing processes but also delves into the nuances of handling file descriptors and executing commands
in a seamless chain.

![](https://raw.githubusercontent.com/andreasbm/readme/master/assets/lines/rainbow.png)

# 🛠️ Program needs

The program run like this :
```bash
./pipex file1 cmd1 cmd2 file2
```

which mimics the real shell command :
```bash
< file1 cmd1 | cmd2 > file2
```

Example :
```bash
./pipex file1.txt "ls -l" "wc -l" file2.txt
```

> [!IMPORTANT]
> In subject, it is requested to manage COMMAND and OPTION in double quotes,
>
> so that means this command :
> ```bash
> ./pipex file1.txt ls -l wc -l file2.txt
> ```
> will fail.

## ⚙️ Usage (mandatory)

Step 1:

Clone the project :
```bash
git clone https://github.com/jotudela/pipex.git && cd pipex
```

---

Step 2:

Compile the project with this :
```bash
make
```
now you have `pipex` executable.

Step 3:

Let's make a simple test. To execute my program, we need an `input` file :
```bash
echo Hello World ! > input.txt
```

---

Step 4:

Now we can execute pipex like this :
```bash
./pipex input.txt "cat" "rev" output.txt
```

this will create a new file `output.txt` which you can read the result : 
```bash
cat output.txt
```

You shoud see this :
```bash
! dlroW olleH
```

![](https://raw.githubusercontent.com/andreasbm/readme/master/assets/lines/rainbow.png)


## ⚙️ Usage (bonus)

Now its really hard

<p align="center">
  <img src="gifs/cestDUR.gif" alt="its really hard">
</p>

Step 1:

Run this in your environment :
```bash
make rebonus
```
now you have `pipex_bonus` executable.

>[!NOTE]
>In the bonus part we need to manage two things :
> - 1 several pipes
> - 2 here_doc
>
>So this
>```bash
>./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2
>```
>should be identical at this
>```bash
>< file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2
>```
>(in theory infinit command)
>
>And this
>```bash
>./pipex here_doc LIMITER cmd cmd1 file
>```
>should be identical at this
>```bash
>cmd << LIMITER | cmd1 >> file
>```

>[!IMPORTANT]
>`Here_doc` is an another way to create a file. In normal times we do this
>```bash
>echo "Hello, World !" > input.txt
>```
>but with here_doc, now we can create a file when we run the program !
>
>Example :
>```bash
>./pipex_bonus here_doc EOF "cat" "rev" output.txt
>> Hello
>> World
>> !
>> EOF
>```
>Now we have a file named `output.txt` which contain
>```bash
>olleH
>dlroW
>!
>```
>(no need to create a file upstream!)
>
>(EOF is a "LIMITER", wich indicate to the program to stop reading from STD_IN)

Step 2:

Let's test here_doc
```bash
./pipex_bonus here_doc EOF cat "wc -l" output.txt
```
you can write any number of line, the result in output.txt is this number.



Let's take `outout.txt` to test n cmd
```bash
./pipex_bonus output.txt "ls -l" rev cat "wc -l" output2.txt
```

Now in `output2.txt` we have :
```bash
      11
```


## Now it's up to you to test !


My final grade :

![](imgs/125_percent.png)

![](https://raw.githubusercontent.com/andreasbm/readme/master/assets/lines/rainbow.png)

## 🤝 Contribution
Contributions are open, make a pull request or open an issue 🚀
