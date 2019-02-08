<h1 align="center">
minishell 
</h1>

<h3 align="center"><b>Description</b></h3>
<p>Première étape de la réalisation d'un shell. Dans ce projet, vous devez réaliser un mini-shell capable de lire et d'évaluer des commandes simples de l'utilisateur. La lecture impliquera une analyse lexicale et syntaxique triviale de la commande, et l'évaluation impliquera de rechercher le binaire correspondant sur la machine et l'exécuter, ou bien d'exécuter le code concerné dans le cas d'une commande "built-in" au shell.</p>

<p><b>Objectif :</b> Analyses lexicale et syntaxique basiques ("lexing" et "parsing") , Exécution d'une commande dans un nouveau processus , Gestion de l'environnement , Gestion du PATH </p>
<p><b>Langage :</b> C.</p>
<p><b>Fonctions autorisées :</b> malloc,free, access, open, close, read, write, opendir, readdir, closedir, getcwd, chdir, stat, lstat, fstat, fork, execve, wait, waitpid, wait3, wait4, signal, kill, exit + d'autres dans le cadre des bonus</p>

<h3 align="center">Fonctionalité</h3>
<p><b>Builtins :</b> echo, cd, setenv, env, unsetenv, exit</p>
<p><b>Expansions :</b> $, ~</p>
<p><b>Options bonus :</b> ; , " , ', droits d'execution</p>
