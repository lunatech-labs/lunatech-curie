(ns curie.core
  (:gen-class))

(defn repl []
  (do
    (print "curie> ")
    (flush)
    (println (str (eval (read-string (read-line)))))
    (repl)))

(defn -main
  [& args]
  (repl))
