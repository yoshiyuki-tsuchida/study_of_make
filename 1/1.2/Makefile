# 1.2 依存関係の検証
#
# # 1.1 節のmakefileの動きを詳しく見ていく
#
#  1. makeのコマンドラインでは、引数でターゲットを指定していないので、ファイルの先頭のターゲットを作成しようとする
#     * ここからスタート
#  2. 必須項目である count_words.o, lexer.o, -lfl に着目する
#  3. まずは count_words.o について検証
#  4. count_words.o というファイルが存在しないので、作成を試みる
#  5. count_words.o をターゲットとしたルールがないか再検証
#  6. ルールはある
#  7. count_words.o をターゲットとして、必須項目の count_words.c について検証
#  8. count_words.c というファイルは存在する
#  9. 必須項目が存在するので、コマンドを実行して count_words.o を作成する
# 10. これで、一番最初の count_words ターゲットの必須項目ではる count_words.o が作成できた
# 11. 次の必須項目は lexer.o
# 12. lexer.o のファイルは存在しない
# 13. ルールを探す
# 14. ある
# 15. lexer.o をターゲットとするルールを検証
# 16. 必須項目は lexer.c
# 17. lexer.c のファイルは存在しない
# 18. ルールを探す
# 19. ある
# 20. lexer.c をターゲットとするルールを検証
# 21. 必須項目は lexer.l
# 22. lexer.l のファイルは存在する
# 23. コマンドを実行して lexer.c を作成する
# 24. lexer.c が存在するので lexer.o をターゲットとするルールでも、コマンドを実行
# 25. lexer.o が作成される
# 26. lexer.o が存在するので count_words をターゲットとするルールでも、コマンドを実行
# 27. 次の必須項目は -lfl
# 28. gcc の -l オプションは、システムライブラリを指示する
# 29. -l<NAME> という指定から、libNAME.so を探す、なければ libNAME.a を探す
# 30. 今回の場合、libfl.a が存在する
# 31. 最終的に count_words の全ての必須項目が揃うので、コマンドを実行できる
# 32. gcc count_words.o lexer.o -lfl -ocount_words

count_words: count_words.o lexer.o -lfl
	gcc count_words.o lexer.o -lfl -ocount_words

count_words.o: count_words.c
	gcc -c count_words.c

lexer.o: lexer.c
	gcc -c lexer.c

lexer.c: lexer.l
	flex -t lexer.l > lexer.c
