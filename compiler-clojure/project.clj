(defproject compiler-clojure "0.0.1-SNAPSHOT"
  :description "Curie is a native lisp dialect geared towards scientific computing."
  :url "https://github.com/lunatech-labs/lunatech-curie"
  :license {:name "Apache License 2.0"
            :url "http://www.apache.org/licenses/LICENSE-2.0"}
  :dependencies [[org.clojure/clojure "1.10.0-RC5"]]
  :main ^:skip-aot curie.core
  :target-path "target/%s"
  :profiles {:uberjar {:aot :all}})
